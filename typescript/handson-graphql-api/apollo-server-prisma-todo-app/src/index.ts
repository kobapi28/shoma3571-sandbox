import { ApolloServer } from 'apollo-server';
import { GraphQLFileLoader } from '@graphql-tools/graphql-file-loader';
import { loadSchemaSync } from '@graphql-tools/load';
import { addResolversToSchema } from '@graphql-tools/schema';
import { join } from 'path';
import { AUTH0_AUDIENCE, AUTH0_DOMAIN } from '../config/constsnts';
import { Context } from './types/context';
import resolvers from './resolvers';
const jwksClient = require('jwks-client');


// schema.graphql で定義したスキーマを読み込んでる
const schema = loadSchemaSync(join(__dirname, '../schema.graphql'), {
  loaders: [new GraphQLFileLoader()]
})



const schemaWithResolvers = addResolversToSchema({ schema, resolvers });
const server = new ApolloServer({ 
  schema: schemaWithResolvers,
  cors: true,
  context: async (ctx) => {
    const token = ctx.req.headers.authorization?.replace('Bearer ', '');
    if (token === undefined) {
      return {
        user: undefined,
      };
    }
    try {
      const user = await new Promise((resolve, reject) => {
        const client = jwksClient({
          jwksUri: `${AUTH0_DOMAIN}/.well-known/jwks.json`,
        });
        jwksClient.verify(
          token,
          (header: any, cb: any) => {
            client.getSigningKey(header.kid, function (err: Error, key: any) {
              const signingKey = key.getPublicKey();
              cb(null, signingKey);
            });
          },
          {
            audience: `${AUTH0_AUDIENCE}`,
            issuer: `${AUTH0_DOMAIN}/`,
            algorithms: ['RS256'],
          },
          (err: Error, decoded: any) => {
            if (err) {
              return reject(err);
            }
            if (decoded === undefined) {
              return reject('decoded is invalid.');
            }
            resolve(decoded);
          }
        );
      });

      const userInfo = await fetch(`${AUTH0_DOMAIN}/userinfo`, {
        headers: {
          Authorization: `Bearer ${token}`,
          'Content-Type': 'application/json',
        },
      }).then((res) => res.json());

      return {
        user: userInfo
      } as Context;
    } catch (error) {
      return {
        user: undefined,
      };
    }
  }
});
// これでも同じっぽい？
// const server = new ApolloServer({ schema, resolvers });

// The `listen` method launches a web server.
server.listen().then(({ url }) => {
  console.log(`🚀  Server ready at ${url}`);
});

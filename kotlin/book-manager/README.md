# Getting Started

### Reference Documentation
For further reference, please consider the following sections:

* [Official Gradle documentation](https://docs.gradle.org)
* [Spring Boot Gradle Plugin Reference Guide](https://docs.spring.io/spring-boot/docs/2.5.6/gradle-plugin/reference/html/)
* [Create an OCI image](https://docs.spring.io/spring-boot/docs/2.5.6/gradle-plugin/reference/html/#build-image)
* [Spring Web](https://docs.spring.io/spring-boot/docs/2.5.6/reference/htmlsingle/#boot-features-developing-web-applications)
* [MyBatis Framework](https://mybatis.org/spring-boot-starter/mybatis-spring-boot-autoconfigure/)

### Guides
The following guides illustrate how to use some features concretely:

* [Building a RESTful Web Service](https://spring.io/guides/gs/rest-service/)
* [Serving Web Content with Spring MVC](https://spring.io/guides/gs/serving-web-content/)
* [Building REST services with Spring](https://spring.io/guides/tutorials/bookmarks/)
* [MyBatis Quick Start](https://github.com/mybatis/spring-boot-starter/wiki/Quick-Start)

### Additional Links
These additional references should also help you:

* [Gradle Build Scans – insights for your project's build](https://scans.gradle.com#gradle)

### Add Test Data
```shell
docker compose exec db /bin/bash
mysql -u root -p
```

```mysql
create database book_manager;
use book_manager;

create table user (
    id bigint NOT NULL,
    email varchar(256) UNIQUE NOT NULL,
    password varchar(128) NOT NULL,
    name varchar(32) NOT NULL,
    role_type enum('ADMIN', 'USER'),
    PRIMARY KEY (id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

create table book (
    id bigint NOT NULL,
    title varchar(128) NOT NULL,
    author varchar(32) NOT NULL,
    release_date date NOT NULL,
    PRIMARY KEY (id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

create table rental (
    book_id bigint NOT NULL,
    user_id bigint NOT NULL,
    rental_datetime datetime NOT NULL,
    return_deadline datetime NOT NULL,
    PRIMARY KEY (book_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


insert into book values
    (100, 'Kotlin入門', 'コトリン太郎', '1950-10-01'),
    (200, 'Java入門', 'ジャバ太郎', '2005-08-29'); 

# passwordはbcryptのアルゴリズムでハッシュ化されたものになっている。
# それぞれ admin, user
insert into user values
    (1, 'admin@test.com', '$2a$08$K4ytU/e5UpwiP6QXLT0agORMd6L/gZswTBbloWD48jTZR6jA7EX8m', 'admin', 'ADMIN'),
    (2, 'user@test.com', '$2a$08$WKRG8goqz5xByBdrZ8ur0ucdIdsbc/wyWMD9/if7IZ5NLa.2HZitm', 'user', 'USER');
```
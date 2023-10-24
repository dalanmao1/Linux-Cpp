# Linux 下 Mysql 的使用（Ubuntu20.04）

[TOC]

## 一、安装

Linux 下 Mysql 的安装非常简单，一个命令即可：

```shell
sudo apt install mysql-server
```

检查安装是否成功，输入：

```shell
mysql -V
```

![20230825145531](https://mubaicppnio.oss-cn-shanghai.aliyuncs.com/20230825145531.png)

## 二、使用

### 2.1 登录

连接服务器时，需要提供用户名和密码

```shell
# 连接远程服务器
mysql -h host -u user -p
# 在本地连接本地的Mysql
mysql -u user -p
```

初次登录可以使用root账户，然后在root账户中创建新用户，再使用上面的命令登录

```shell
# 登录 root 用户（密码是安装的时候让填的，如果没有填就是没有密码）
sudo mysql -u root

# 将new_user和new_password替换为要创建的新用户的用户名和密码
CREATE USER 'new_user'@'localhost' IDENTIFIED BY 'new_password';

# 这步很重要，赋予new_user用户所有权限，否则在后续操作时会提示该用户没有权限
GRANT ALL PRIVILEGES ON *.* TO 'new_user'@'localhost' WITH GRANT OPTION;

# 退出当前Mysql用户
exit

# 登录新创建的用户
$ mysql -u new_user -p
```

如果要查看更多的Mysql的选项列表，可以输入

```shell
mysql --help  
```

### 2.2 数据库操作

使用SHOW语句可以找出服务器上当前存在哪些数据库：

```shell
# SHOW DATABASES;或者换成小写都是可以的
mysql> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| RUNOOB             |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.00 sec)
```

#### 2.2.1 创建数据库

在登陆 MySQL 服务后，使用 create 命令创建数据库，语法如下:

```shell
CREATE DATABASE 数据库名;
```

```shell
# 创建数据库
mysql> CREATE DATABASE test;
Query OK, 1 row affected (0.03 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| RUNOOB             |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| test               |
+--------------------+
6 rows in set (0.00 sec)
```

**USE命令用于切换当前连接的活动数据库**，当连接到MySQL服务器时，默认情况下可能没有选择任何数据库。为了执行针对特定数据库的SQL查询（例如SELECT、INSERT、UPDATE、DELETE等），需要先告诉MySQL想要操作哪个数据库

```shell
USE 数据库名;
```

#### 2.2.2 删除数据库

drop 命令删除数据库，命令格式：

```shell
drop database 数据库名;
```

#### 2.2.3 创建数据表

创建MySQL数据表的SQL通用语法：

```shell
CREATE TABLE table_name (column_name column_type, column_name1 column_type1,...);
```

Mysql数据类型：[https://www.runoob.com/mysql/mysql-data-types.html](https://www.runoob.com/mysql/mysql-data-types.html)

```shell
# 创建一个表
mysql> CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sex CHAR(1), birth DATE, death DATE);
Query OK, 0 rows affected (0.14 sec)

# 查看表的情况
mysql> show tables;
+----------------+
| Tables_in_test |
+----------------+
| pet            |
| test_table     |
+----------------+
2 rows in set (0.00 sec)

# 查看表的各种属性
mysql> describe pet;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| name    | varchar(20) | YES  |     | NULL    |       |
| owner   | varchar(20) | YES  |     | NULL    |       |
| species | varchar(20) | YES  |     | NULL    |       |
| sex     | char(1)     | YES  |     | NULL    |       |
| birth   | date        | YES  |     | NULL    |       |
| death   | date        | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
6 rows in set (0.01 sec)
```

#### 2.2.4 删除数据表

```shell
DROP TABLE table_name;
```

#### 2.2.5 插入数据

**方式一：** MySQL数据表插入数据通用的 INSERT INTO SQL语法：

```shell
INSERT INTO table_name ( field1, field2,...fieldN )
                       VALUES
                       ( value1, value2,...valueN );
```

例如，在上一节的表pet插入信息：

```shell
# 插入信息
mysql> INSERT INTO pet (name, owner, species, sex, birth, death) 
    -> VALUES ('Puffball','Diane','hamster','f','1999-03-30',NULL);

# 查看表中信息
mysql> select * from pet;
+----------+-------+---------+------+------------+-------+
| name     | owner | species | sex  | birth      | death |
+----------+-------+---------+------+------------+-------+
| Puffball | Diane | hamster | f    | 1999-03-30 | NULL  |
+----------+-------+---------+------+------------+-------+
1 row in set (0.00 sec)
```

**方式二：** 导入外部文本

新建一个.txt文本，每行包含一条记录，值由制表符分隔；对于缺失值，使用NULL，在文本文件中表示这些内容使用 \N（反斜杠、大写 N）表示，如下：

pet.txt

```shell
Bob     Balan   dog     \N      1997-09-18      \N
```

插入命令：

```shell
LOAD DATA LOCAL INFILE '/home/nio/workspace/gitWorkspace/pet.txt' INTO TABLE pet;
```

针对方法二报错问题：

```shell
# 报错：
ERROR 3948 (42000): Loading local data is disabled; this must be enabled on both the client and server sides

# 将以下配置添加到MySQL服务器的配置文件（my.cnf或my.ini）中的[mysqld]部分
[mysqld]
local-infile=1

# 客户端登录
mysql -u your_username -p --local-infile=1
```

## 参考文档

[https://dev.mysql.com/doc/refman/8.1/en/entering-queries.html](https://dev.mysql.com/doc/refman/8.1/en/entering-queries.html)

[https://www.runoob.com/mysql/mysql-connection.html](https://www.runoob.com/mysql/mysql-connection.html)
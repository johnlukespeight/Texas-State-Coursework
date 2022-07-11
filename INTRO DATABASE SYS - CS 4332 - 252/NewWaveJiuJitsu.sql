/*
John-Luke Speight
PROJECT 9
CS 4332.252
DUE: 04/23/22
*/

CREATE DATABASE NewWaveJiuJitsu;

CREATE TABLE CLASSES ( classTime DATETIME, instructor VARCHAR(45) NOT NULL, employeeID VARCHAR(100), CONSTRAINT CLASS_INST PRIMARY KEY(instructor,employeeID));

INSERT INTO CLASSES values( 09-19-2022, 'Danaher,John', 000000);
INSERT INTO CLASSES values( 01-13-2022, 'Ryan,Gordon', 111111);
INSERT INTO CLASSES values( 06-03-2022, 'Tonon,Garry', 222222);

CREATE TABLE PROFESSOR ( firstName VARCHAR(100), lastName VARCHAR(100) NOT NULL, employeeID VARCHAR(100));

INSERT INTO PROFESSOR values ( 'John', 'Danaher', 000000);
INSERT INTO PROFESSOR values ( 'Gordon', 'Ryan', 111111);
INSERT INTO PROFESSOR values( 'Garry', 'Tonon', 222222);

CREATE TABLE SALES ( apparel VARCHAR(100), apparelCount int,  privateLesson int,  memberships int, studentNumber int);

INSERT INTO SALES values( 'rashGuard', 1, 1, 1, 1234);
INSERT INTO SALES values( 'gi', 2, 10, 3, 4444);
INSERT INTO SALES values( 'teeShortSleeve', 3, 12, 4, 7777);

CREATE TABLE STUDENT ( firstName VARCHAR(100), lastName VARCHAR(100), studentAddress VARCHAR(100), studentEmail VARCHAR(MAX), formOfPayment VARCHAR(100), creditCardNumber int, studentNumber int);

INSERT INTO STUDENT values( 'John-Luke', 'Speight', '47 Robinson st, New Brunswick, NJ 08901', 'johnlukespeight@gmail.com', 'Visa', 000000000000, 0123 );
INSERT INTO STUDENT values( 'Daniel', 'Manasiou', '123 Congress Ave, Austin, TX 78701', 'manasioudaniel@nwjj.com', 'Mastercard', 111111111111, 0000);
INSERT INTO STUDENT values ('Griffiths', 'Luke', '112 COngress Ave, Austin, TX 78701', 'griffithsluke@nwjj.com', 'AmericanExpress', 000011110000, 0101);



#John-Luke Speight
CREATE DATABASE PROJECT1;
USE PROJECT1;


CREATE TABLE STUDENT(StudentNumber int, LastName varchar(255), FirstName varchar(255), EmailAddress varchar(255));
INSERT INTO STUDENT (StudentNumber, LastName, FirstName, EmailAddress)
VALUES (1, 'Cooke', 'Sam', 'Sam.Cooke@OurU.edu'),
		(2, 'Lau', 'Marcia', 'Marcia.Lau@OurU.edu'),
		(3, 'Harris', 'Lou', 'Lou.Harris@OurU.edu'),
		(4, 'Greene', 'Grace', 'Grace.Greene@OurU.edu');
SELECT * FROM PROJECT1.STUDENT;
        
CREATE TABLE GRADE(StudentNumber int, ClassNumber int, Grade double);
INSERT INTO GRADE(StudentNumber, ClassNumber, Grade)
VALUES (1,12,3.7),
		(1,40,3.5),
        (2,20,3.7),
        (3,30,3.1),
        (4,40,3.0),
        (4,50,3.5);
	

CREATE TABLE Class(ClassNum int, ClassName varchar(16), Term varchar(16), Section int);
INSERT INTO Class(ClassNum, ClassName, Term, Section)
VALUES (10,'CHEM 101', '2017-Fall',1),
		(20,'CHEM 101','2017-Fall',2),
        (30,'CHEM 101','2018-Spring',1),
		(40,'ACCT 101','2017-Fall',1),
        (50,'ACCT 101','2018-Spring',1);

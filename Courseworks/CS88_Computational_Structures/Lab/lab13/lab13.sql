.read data.sql

-- Q2
CREATE TABLE obedience as
  -- REPLACE THIS LINE
  SELECT seven, denero FROM students;


-- Q3
CREATE TABLE blue_dog as
  -- REPLACE THIS LINE
  SELECT color, pet FROM students WHERE color = "blue" AND pet = "dog";


-- Q4
CREATE TABLE smallest_int as
  -- REPLACE THIS LINE
  SELECT time, smallest FROM students WHERE smallest > 6 ORDER BY smallest LIMIT 20;


-- Q5
CREATE TABLE sevens as
  -- REPLACE THIS LINE
  SELECT a.seven FROM students as a, checkboxes as b WHERE a.time = b.time AND a.number = 7 AND b.'7' = 'True';


-- Q6
CREATE TABLE matchmaker as
  -- REPLACE THIS LINE
  SELECT a.pet, a.song, a.color, b.color FROM students as a, students as b
  WHERE a.pet = b.pet AND a.song = b.song AND a.time < b.time;



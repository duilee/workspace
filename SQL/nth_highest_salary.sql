CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT CASE WHEN COUNT(sub.Salary) < N THEN NULL
                  ELSE MIN(sub.Salary)
             END
      FROM (
            SELECT DISTINCT salary
            FROM employee
            ORDER BY salary DESC
            LIMIT N
            ) sub
  );
END



CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT IF(COUNT(sub.salary) < N, NULL, MIN(sub.salary))
             END
      FROM (
            SELECT DISTINCT salary
            FROM employee
            ORDER BY salary DESC
            LIMIT N
            ) sub
  );
END



CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      DECLARE P INT;
      SET P = N - 1;
  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT salary
        FROM employee
        ORDER BY salary DESC
        LIMIT P, 1
        -- or LIMIT 1 OFFSET P
  );
END
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      DECLARE c, s INT;
      DECLARE re INT DEFAULT NULL;
      SET s = N - 1;
      SELECT count(*) INTO c FROM Employee;
      IF (N <= c) THEN
            SELECT DISTINCT (Salary) INTO re FROM Employee ORDER BY Salary DESC LIMIT s, 1;
              END IF;

              RETURN (re);
END

select max(Salary) from Employee where Salary < (select max(Salary) from Employee)

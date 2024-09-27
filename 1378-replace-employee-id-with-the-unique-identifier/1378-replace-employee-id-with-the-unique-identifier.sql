# Write your MySQL query statement below
select unique_id, name from Employees as e LEFT JOIN EmployeeUNI as u ON 
e.id = u.id;
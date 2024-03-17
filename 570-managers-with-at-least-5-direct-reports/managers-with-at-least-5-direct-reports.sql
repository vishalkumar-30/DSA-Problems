# Write your MySQL query statement below
SELECT e1.name
FROM Employee e1
INNER JOIN Employee e2
ON e1.id = e2.managerId
group by e1.id
HAVING count(e2.managerId)>=5;


-- SELECT e.name
-- FROM Employee e ,Employee m
-- WHERE e.id = m.managerId 
-- GROUP BY e.id
-- HAVING COUNT(m.id) >= 5
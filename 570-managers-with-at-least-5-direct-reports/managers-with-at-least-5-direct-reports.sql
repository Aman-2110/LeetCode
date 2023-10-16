select e1.name
from Employee e1 join Employee e2
on e1.id = e2.managerId
group by e1.name, e1.id
having count(e1.name) >= 5
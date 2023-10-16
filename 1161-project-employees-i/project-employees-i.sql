select project_id, ROUND(AVG(CAST(experience_years as Decimal(10, 2))), 2) as average_years 
from Project p left join Employee e
on p.employee_id = e.employee_id
group by project_id
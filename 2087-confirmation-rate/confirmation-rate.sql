select s.user_id, ROUND(AVG(CASE WHEN action = "confirmed" THEN 1 ELSE 0 END), 2) as confirmation_rate 
from Signups s left join Confirmations c
on s.user_id = c.user_id
group by s.user_id
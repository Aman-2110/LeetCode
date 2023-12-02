select DATE_FORMAT(trans_date, '%Y-%m') as month, country, count(*) as trans_count,sum( CASE WHEN state ="approved" Then 1 ELSE 0 END) as approved_count, sum(amount) as trans_total_amount, sum(IF(state = 'approved', amount, 0)) as approved_total_amount 
from Transactions
group by month, country
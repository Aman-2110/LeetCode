select p.product_id, (
  case
    when count(p.product_id) = 1 then if(u.units is null,0,p.price)
    else round(sum(p.price * u.units) / sum(u.units),2) # aggregate function by default ignore null values
  end
) as average_price
from prices as p left join unitssold as u
on p.product_id = u.product_id and (u.purchase_date between p.start_date and p.end_date)
group by p.product_id;
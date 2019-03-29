#!/bin/sh

# echo '#!/bin/sh' > /tmp/nv.sh
# sed 's/^\(.*\)=.*/nvram set \1=""/g' /tmp/nv.txt >> /tmp/nv.sh
# echo 'nvram commit' >> /tmp/nv.sh

echo '#!/bin/sh' > /tmp/nv.sh
#echo 'nvram set k3_macaddr1=`nvram get 1:macaddr`' >> /tmp/nv.sh
#echo 'nvram set k3_macaddr2=`nvram get 2:macaddr`' >> /tmp/nv.sh
#echo 'nvram commit' >> /tmp/nv.sh

chmod +x /tmp/nv.sh

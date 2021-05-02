kill $(ps aux | grep 'ros' | awk '{print $2}')
kill $(ps aux | grep 'gz' | awk '{print $2}')

set -e

# enter embedded dir
curdir=$(pwd)
cd bin.linux/embeddedD

# start mysql server
echo "starting server"
sh start_server.sh &
sleep 5

# run client in to upload dump
echo "running query"
sh run_query.sh ../../../LemLat_Data/lemlat_db.sql

# stop mysql server
echo "stopping server"
sh stop_server.sh
sleep 5

# delete logfile
rm -f data/*.err

# return to current dir
cd $curdir


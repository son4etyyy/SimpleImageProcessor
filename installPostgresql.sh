sudo apt-get update
sudo apt-get install postgresql-9.3
export PATH=/usr/lib/postgresql/9.3/bin:$PATH:/usr/sbin
export PGDATA=/var/lib/postgresql/9.3/main
export PGPORT=5432
sudo apt-get install postgresql postgresql-contrib
sudo apt-get install pgadmin3
sudo -u postgres psql postgres
sudo -u postgres createdb mydb
sudo apt-get install postgresql-contrib
sudo nano /etc/postgresql/9.3/main/pg_hba.conf
# instead:
# # Database administrative login by Unix domain socket
# local   all             postgres                                peer
# write:
# # Database administrative login by Unix domain socket
# local   all             postgres                                md5

sudo /etc/init.d/postgresql reload
pgadmin3

mypassword=$1
echo $mypassword | sudo -S apt-get -y update
echo $mypassword | sudo -S apt-get -y install postgresql-9.3
export PATH=/usr/lib/postgresql/9.3/bin:$PATH:/usr/sbin
export PGDATA=/var/lib/postgresql/9.3/main
export PGPORT=5432
echo $mypassword | sudo -S apt-get -y install postgresql postgresql-contrib
echo $mypassword | sudo -u -S postgres psql postgres
echo $mypassword | sudo -S apt-get -y install postgresql-contrib
echo $mypassword | sudo sed -e s/'local   all             postgres                                peer'/'local   all             postgres                                md5'/ /etc/postgresql/9.3/main/pg_hba.conf
echo $mypassword | sudo -S /etc/init.d/postgresql reload
userToAdd=$(whoami)
echo $mypassword | sudo -u postgres createuser $userToAdd

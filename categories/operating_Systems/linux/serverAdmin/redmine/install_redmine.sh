#!/bin/bash

#
# install_redmine.sh - Expirience and notes of Redmine Installation (incomplete)
#	Official link: http://www.redmine.org/projects/redmine/wiki/redmineinstall
#
# Author: Marco Túlio R Braga
# Create date: Aug 22, 2015
# Last update: Aug 30, 2015
#

##################

PATH_DOWNLOAD="/vagrant/vm_donwload"

###################
INSTALL() {
  # Installing PostgreSQL (http://www.liquidweb.com/kb/how-to-install-and-connect-to-postgresql-on-centos-7/)
  wget http://yum.postgresql.org/9.3/redhat/rhel-7-x86_64/pgdg-centos93-9.3-1.noarch.rpm -P ${PATH_DOWNLOAD}
  rpm -iUvh ${PATH_DOWNLOAD}/pgdg-centos93-9.3-1.noarch.rpm
  yum -y install postgresql93 postgresql93-server postgresql93-contrib postgresql93-libs

  ## Enabling PostgreSQL
  echo "Editar o arquivo de configuração do PG com as seguintes linhas / Edit Pg config file - like follow config:" 
  # IPv4 local connections: host all all 127.0.0.1/32 trust
  # IPv6 local connections: host all all ::1/128 trust
  systemctl enable postgresql-9.3
  /usr/pgsql-9.3/bin/postgresql93-setup initdb
  systemctl start postgresql-9.3

  ## Run it
  # Configure PostgreSQL
  ## Show users
  # \du
  ## Creating user
  # CREATE ROLE USRREDMINE LOGIN ENCRYPTED PASSWORD 'PASSWDREDMINE' NOINHERIT VALID UNTIL 'infinity';
  ## List databases
  # \l
  ## Changing database
  # CREATE DATABASE DBREDMINE WITH ENCODING='UTF8' OWNER=USRREDMINE;
  # grant connect on database dbredmine to usrredmine ;
 
  # ONLY NOTE - DONT'T DO THIS: 
  #echo "CREATE ROLE USRREDMINE LOGIN ENCRYPTED PASSWORD 'PASSWDREDMINE' NOINHERIT VALID UNTIL 'infinity';
#CREATE DATABASE DBREDMINE WITH ENCODING='UTF8' OWNER=USRREDMINE;" > run_sql_redmine.sql


  ###############################
  # Install Ruby
  yum install -y ruby rubygem rubygems-2.0.14-24.el7.noarch ruby-devel.x86_64 zlib-devel patch libpqxx-devel.x86_64

  # Download Redmine (See latest in http://www.redmine.org/projects/redmine/wiki/Download)
  wget http://www.redmine.org/releases/redmine-3.1.0.tar.gz -P ${PATH_DOWNLOAD}

}

##############################
SETUP() {

  ## Unpacking Redmine
  # Unpacking
  tar xfz ${PATH_DOWNLOAD}/redmine-3.1.0.tar.gz -C ${PATH_DOWNLOAD}
  cd ${PATH_DOWNLOAD}/redmine-3.1.0

  # Database configuration
  echo "production:
  adapter: postgresql
  database: DBREDMINE
  host: 127.0.0.1
  username: USRREDMINE
  password: PASSWDREDMINE
  encoding: utf8
  schema_search_path: public" >> config/database.yml
  
  ## Install using Ruby installation scripts
  test -d /root/bin || mkdir /root/bin >/dev/null 2>&1
  PATH=${PATH}:/root/bin

  # Starting installationg
  gem install bundler
  bundle install --without development test

  ### to avoid an error of "secret_token", do it:
  # Error on http://IP: Missing `secret_token` and `secret_key_base` for 'production' environment, set these values in `config/secrets.yml` 
  bundle exec rake generate_secret_token

  # http://guides.rubyonrails.org/upgrading_ruby_on_rails.html#config-secrets-yml
  # Add to config/secrets.yml:
#development:
#  secret_key_base:
#test:
#  secret_key_base:
#production:
#  secret_key_base: <%= ENV["SECRET_KEY_BASE"] %>

  # Populating DB
  RAILS_ENV=production bundle exec rake db:migrate
  RAILS_ENV=production bundle exec rake redmine:load_default_data

  # Testing binding - listeing in all port 80
  bundle exec rails server webrick -e production --binding=0.0.0.0 --port=80

}


##############################
ENABLE() {

  echo "Is it configurated to run at system startup?"

}


##############################
TEST() {

  curl http://127.0.0.1

}


##############################
main() {
  #INSTALL;
  #SETUP;
  #ENABLE;
  #TEST;
}
main $@



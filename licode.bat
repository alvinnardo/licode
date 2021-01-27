@echo off
git config --global user.email "hiderygreen@gmail.com"
git add .
git commit -m "update licode"
git pull origin master
git push origin master
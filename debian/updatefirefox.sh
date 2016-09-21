# use this script to fetch the latest firefox release and install it 
# input the name of the tar.bz2 that you have downloaded
cd ~/tars
sudo rm -rf /usr/lib/firefox
sudo tar -xjvf $1 -C /usr/lib/
sudo rm -rf /usr/bin/firefox
cd /usr/bin
sudo ln -s /usr/lib/firefox/firefox 
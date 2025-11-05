#!/bin/bash

mkdir ~/myDirectory/secondDirectory -p
touch ~/myDirectory/secondDirectory/myNotePaper.txt
cp ~/myDirectory/secondDirectory/myNotePaper.txt ~/myDirectory/
mv ~/myDirectory/myNotePaper.txt ~/myDirectory/myOldNotePaper.txt

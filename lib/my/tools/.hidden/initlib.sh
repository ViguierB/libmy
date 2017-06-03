## initlib for libmy in /home/benji_epitech/workdir/perso/libmy/lib/my/tools
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
## 
## Started on  Mon May 22 18:52:56 2017 Benjamin Viguier
## Last update Sat Jun  3 16:06:27 2017 Benjamin Viguier
#!/bin/bash

if [ -d "./lib" ]; then
    if [ ! -d "./include" ]; then
        mkdir include;
    fi
    if [ ! -d "./src" ]; then
        mkdir src;
    fi
    if [ ! -f "./include/libmy.h" ]; then
	ln -s ../lib/my/include/libmy.h include/libmy.h;
    fi
    if [ ! -f "./include/depend.mk" ]; then
	ln -s ../lib/my/include/depend.mk include/depend.mk;
    fi
    if [ ! -f "./include/macro.h" ]; then
	ln -s ../lib/my/include/macro.h include/macro.h;
    fi
    if [ ! -d "./tools" ]; then
	ln -s ./lib/my/tools ./tools;	
    fi
else
    echo "Pas dans le bon dossier"
fi    

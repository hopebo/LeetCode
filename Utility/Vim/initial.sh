#!/bin/bash

#install Vundle plugins manager
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

#compile ~/.vimrc
cd ~
file=".vimrc"
if [ -e ${file} ]; then : > ${file}; else touch ${file}; fi

config="\
set nocompatible\n\
filetype off\n\
set rtp+=~/.vim/bundle/Vundle.vim\n\
call vundle#begin()\n\
\n\
Plugin 'VundleVim/Vundle.vim'\n\
Plugin 'altercation/vim-colors-solarized'\n\
\n\
call vundle#end()\n\
filetype plugin indent on\n\
"
echo -e ${config} >> ${file}

#install plugins
vim +PluginInstall +qall

#add plugin configuration
#Solarized
config="\
syntax enable\n\
set background=dark\n\
colorscheme solarized\n\
"
echo -e ${config} >> ${file}

#others
#Indent
config="\
set tabstop=4\n\
set softtabstop=4\n\
set shiftwidth=4\n\
set noexpandtab\n\
set autoindent\n\
"
echo -e ${config} >> ${file}

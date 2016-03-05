runtime bundle/vim-pathogen/autoload/pathogen.vim
call pathogen#infect()

syntax enable

if &t_Co < 256
  colorscheme default
  set nocursorline
else
  set background=dark
  let g:solarized_visibility = "high"
  let g:solarized_contrast = "high"
  let g:solarized_termcolors=17
  colorscheme solarized
endif

set expandtab
set shiftwidth=2
set softtabstop=2

filetype plugin indent on

let g:paredit_mode = 1
let g:rainbow_active = 1
let NERDTreeShowHidden=1

set list
set listchars=tab:▸\ ,eol:¬

autocmd BufRead,BufNewFile *.cljs setlocal filetype=clojure

set number

inoremap kj <ESC>
let mapleader=","

runtime bundle/vim-pathogen/autoload/pathogen.vim
call pathogen#infect()

syntax enable

if &t_Co < 256
	colorscheme default
	set nocursorline
else
	set background=dark
	colorscheme solarized
	let g:solarized_termcolors=256
endif

set expandtab
set shiftwidth=2
set softtabstop=2

filetype plugin indent on
let g:paredit_mode = 1

set list
set listchars=tab:▸\ ,eol:¬

autocmd BufRead,BufNewFile *.cljs setlocal filetype=clojure

set number

let NERDTreeWinSize = 20
let NERDTreeShowHidden=1

inoremap kj <ESC>
map ö $
map 0 ^
map D <C-D>
map U <C-U>


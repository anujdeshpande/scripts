
PATH=$PATH:$HOME/.rvm/bin # Add RVM to PATH for scripting

### Added by the Heroku Toolbelt
export PATH="/usr/local/heroku/bin:$PATH"
export PATH="/usr/local/angstrom/arm/bin:$PATH"
### Alias
alias l='rm *~;ls -l'
alias ..='cd ..'
alias ...='cd ../../'
alias ....='cd ../../../'
alias e='exit'
alias st='git status'
alias log='git log --oneline'
alias sd='sudo shutdown -h now'
alias o='open -a'
alias p='pwd'
alias c='clear'
alias commit='git commit -m'
alias sshpi='ssh root@192.168.2.10'
alias sftppi='sftp root@192.168.2.10'
alias emacs='o Aquamacs'
### Bashmarks
source ~/.local/bin/bashmarks.sh

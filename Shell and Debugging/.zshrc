export PATH="/opt/homebrew/opt/openssl@1.1/bin:$PATH"
export PATH="/opt/homebrew/opt/openssl@1.1/bin:$PATH"
export PATH="/opt/homebrew/opt/libarchive/bin:$PATH"

eval $(thefuck --alias)
export PATH="/opt/homebrew/opt/llvm/bin:$PATH"
export PATH="/opt/homebrew/opt/ruby/bin:$PATH"
eval 'export PATH="/Users/cwg1231/.rbenv/shims:${PATH}"
export RBENV_SHELL=zsh
source '/opt/homebrew/Cellar/rbenv/1.2.0/libexec/../completions/rbenv.zsh'
command rbenv rehash 2>/dev/null
rbenv() {
  local command
  command="${1:-}"
  if [ "$#" -gt 0 ]; then
    shift
  fi

  case "$command" in
  rehash|shell)
    eval "$(rbenv "sh-$command" "$@")";;
  *)
    command rbenv "$command" "$@";;
  esac
}'

eval "$(rbenv init - zsh)"

# manually added aliases
alias cleartex="rm *.aux && echo 'Cleared aux files'; rm *.log && echo 'Cleared log files'; rm *.out && echo 'Cleared out files'; rm *.synctex.gz && echo 'Cleared synctex.gz files'"

function hackerman()
{
	echo "Starting wireless interfaces..."
	sleep 1
	echo "Enabling VPN..." 
	sleep 1
	echo "Circumscribing blinkenlights..."
	sleep 1
	echo "Haranguing gefingerpoken..."
	sleep 1
	echo "Finishing up..."
	sleep 1
	echo "Done."
}

function hack_pentagon()
{
	tmux new-session -d -s hack_pentagon \; send "tmux split" Enter
	tmux send -t hack_pentagon.0 htop Enter

	echo "Bypassing firewall..."
	sleep 1
	echo "Disabling security..."
	sleep 1
	echo "**RADAR DETECTED!**"
	echo "Evading detection..." 
	sleep 1

	tmux send -t hack_pentagon.1 "PROMPT='jbiden@pentagon_mcdonalds_server homework_folder $ '" Enter 
	tmux send -t hack_pentagon.1 clear Enter 
	tmux send -t hack_pentagon.1 hackerman Enter

	tmux attach
}

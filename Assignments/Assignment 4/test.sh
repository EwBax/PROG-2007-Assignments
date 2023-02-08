returnStatus=0

# Only show colours on local "Git Bash" terminal
passFormat="if [ $TERM = "xterm" ]; then tput sgr0 && tput setaf 2; fi"
failFormat="if [ $TERM = "xterm" ]; then tput sgr0 && tput setaf 1; fi"
normalFormat="if [ $TERM = "xterm" ]; then tput sgr0; fi"

# If not on Linux set output to .exe
unameValue="$(uname -s)"
echo "Testing OS Platform: $unameValue"
fileExtension=".exe"
if [  $unameValue = "Linux" ] || [  $unameValue = "Darwin" ] ; then
    fileExtension=".out"
fi

echo "Running tests..."
echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
1
We live on a placid island of ignorance
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_1=$(./a$fileExtension <<'EOF'
1
We live on a placid island of ignorance
EOF
)

# don't worry about extra whitespace in the output
newOutput_1=""
while read line
do
  newOutput_1=$newOutput_1$(echo "$line" | xargs)
done <<< "$output_1"

expected_output_1="244 157 133 227 230 245 157 133 236 237 133 145 133 239 227 145 147 230 146 133 230 232 227 145 237 146 133 236 156 133 230 228 237 236 233 145 237 147 157"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_1" <<< "$newOutput_1"; then
  eval "$passFormat"
  echo "Test #1 - Encrypt Lovecraft 1 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #1 - Encrypt Lovecraft 1 - Expected '$expected_output_1' but got: $newOutput_1"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
2
244 157 133 227 230 245 157 133 236 237 133 145 133 239 227 145 147 230 146 133 230 232 227 145 237 146 133 236 156 133 230 228 237 236 233 145 237 147 157
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_2=$(./a$fileExtension <<'EOF'
2
244 157 133 227 230 245 157 133 236 237 133 145 133 239 227 145 147 230 146 133 230 232 227 145 237 146 133 236 156 133 230 228 237 236 233 145 237 147 157
EOF
)

# don't worry about extra whitespace in the output
newOutput_1=""
while read line
do
  newOutput_2=$newOutput_2$(echo "$line" | xargs)
done <<< "$output_2"

expected_output_2="WE LIVE ON A PLACID ISLAND OF IGNORANCE"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_2" <<< "$newOutput_2"; then
  eval "$passFormat"
  echo "Test #2 - Decrypt Lovecraft 1 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #2 - Decrypt Lovecraft 1 - Expected '$expected_output_2' but got: $newOutput_2"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
1
in the midst of black seas of infinity,
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_3=$(./a$fileExtension <<'EOF'
1
in the midst of black seas of infinity,
EOF
)

# don't worry about extra whitespace in the output
newOutput_3=""
while read line
do
  newOutput_3=$newOutput_3$(echo "$line" | xargs)
done <<< "$output_3"

expected_output_3="230 237 133 235 231 157 133 226 230 146 232 235 133 236 156 133 144 227 145 147 224 133 232 157 145 232 133 236 156 133 230 237 156 230 237 230 235 246 141"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_3" <<< "$newOutput_3"; then
  eval "$passFormat"
  echo "Test #3 - Encrypt Lovecraft 2 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #3 - Encrypt Lovecraft 2 - Expected '$expected_output_3' but got: $newOutput_3"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
2
230 237 133 235 231 157 133 226 230 146 232 235 133 236 156 133 144 227 145 147 224 133 232 157 145 232 133 236 156 133 230 237 156 230 237 230 235 246 141
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_4=$(./a$fileExtension <<'EOF'
2
230 237 133 235 231 157 133 226 230 146 232 235 133 236 156 133 144 227 145 147 224 133 232 157 145 232 133 236 156 133 230 237 156 230 237 230 235 246 141
EOF
)

# don't worry about extra whitespace in the output
newOutput_4=""
while read line
do
  newOutput_4=$newOutput_4$(echo "$line" | xargs)
done <<< "$output_4"

expected_output_4="IN THE MIDST OF BLACK SEAS OF INFINITY,"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_4" <<< "$newOutput_4"; then
  eval "$passFormat"
  echo "Test #4 - Decrypt Lovecraft 2 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #4 - Decrypt Lovecraft 2 - Expected '$expected_output_4' but got: $newOutput_4"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
1
and it was not meant that we should voyage far.
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_5=$(./a$fileExtension <<'EOF'
1
and it was not meant that we should voyage far.
EOF
)

# don't worry about extra whitespace in the output
newOutput_5=""
while read line
do
  newOutput_5=$newOutput_5$(echo "$line" | xargs)
done <<< "$output_5"

expected_output_5="145 237 146 133 230 235 133 244 145 232 133 237 236 235 133 226 157 145 237 235 133 235 231 145 235 133 244 157 133 232 231 236 234 227 146 133 245 236 246 145 228 157 133 156 145 233 131"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_5" <<< "$newOutput_5"; then
  eval "$passFormat"
  echo "Test #5 - Encrypt Lovecraft 3 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #5 - Encrypt Lovecraft 3 - Expected '$expected_output_5' but got: $newOutput_5"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
2
145 237 146 133 230 235 133 244 145 232 133 237 236 235 133 226 157 145 237 235 133 235 231 145 235 133 244 157 133 232 231 236 234 227 146 133 245 236 246 145 228 157 133 156 145 233 131
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_6=$(./a$fileExtension <<'EOF'
2
145 237 146 133 230 235 133 244 145 232 133 237 236 235 133 226 157 145 237 235 133 235 231 145 235 133 244 157 133 232 231 236 234 227 146 133 245 236 246 145 228 157 133 156 145 233 131
EOF
)

# don't worry about extra whitespace in the output
newOutput_6=""
while read line
do
  newOutput_6=$newOutput_6$(echo "$line" | xargs)
done <<< "$output_6"

expected_output_6="AND IT WAS NOT MEANT THAT WE SHOULD VOYAGE FAR."

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_6" <<< "$newOutput_6"; then
  eval "$passFormat"
  echo "Test #6 - Decrypt Lovecraft 3 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #6 - Decrypt Lovecraft 3 - Expected '$expected_output_6' but got: $newOutput_6"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
7
Blah
EOF

if [ $? -eq 1 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited with correct error code"
else
  eval "$failFormat"
  echo "Fail: Program did not exit with correct error code"
  returnStatus=1
fi

output_7=$(./a$fileExtension <<'EOF'
7
Blah
EOF
)

# don't worry about extra whitespace in the output
newOutput_7=""
while read line
do
  newOutput_7=$newOutput_7$(echo "$line" | xargs)
done <<< "$output_7"

expected_output_7="So, you do not know what you want!"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_7" <<< "$newOutput_7"; then
  eval "$passFormat"
  echo "Test #7 - Bad Choice - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #7 - Bad Choice - Expected '$expected_output_7' but got: $newOutput_7"
  returnStatus=1
fi

echo

if [ $returnStatus -eq 0 ] ; then
    eval "$passFormat"
    echo "All tests passed."
else
    eval "$failFormat"
    echo "One or more tests failed."
fi

eval "$normalFormat"

echo
exit $returnStatus

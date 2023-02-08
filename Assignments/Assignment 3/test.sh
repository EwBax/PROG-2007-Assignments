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
5555555
Trudeau
Justin
OSYS1000
92
PROG2007
81
SAAD1001
77
PROG1400
94
DBAS4002
75
6666666
Ardern
Jacinda
OSYS1000
96
PROG2007
84
SAAD1001
75
PROG1400
98
DBAS4002
86
7777777
Biden
Joe
OSYS1000
94
PROG2007
87
SAAD1001
70
PROG1400
88
DBAS4002
89
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

echo

output=$(./a$fileExtension <<'EOF'
5555555
Trudeau
Justin
OSYS1000
92
PROG2007
81
SAAD1001
77
PROG1400
94
DBAS4002
75
6666666
Ardern
Jacinda
OSYS1000
96
PROG2007
84
SAAD1001
75
PROG1400
98
DBAS4002
86
7777777
Biden
Joe
OSYS1000
94
PROG2007
87
SAAD1001
70
PROG1400
88
DBAS4002
89
EOF
)

# don't worry about extra whitespace in the output
newOutput=""
while read line
do
  newOutput=$newOutput$(echo "$line" | xargs)
done <<< "$output"

################### JUSTIN TESTS ################################

expected_output_1="Student: ID:5555555 Name: Trudeau, Justin"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_1" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #1 Justin Header - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #1 Justin Header - Expected '$expected_output_1' but got: $newOutput"
  returnStatus=1
fi

expected_output_2="Course name: OSYS1000 Course mark: 92"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_2" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #2 Justin OSYS1000 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #2 Justin OSYS1000 - Expected '$expected_output_2' but got: $newOutput"
  returnStatus=1
fi

expected_output_3="Course name: PROG2007 Course mark: 81"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_3" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #3 Justin PROG2007 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #3 Justin PROG2007 - Expected '$expected_output_3' but got: $newOutput"
  returnStatus=1
fi

expected_output_4="Course name: SAAD1001 Course mark: 77"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_4" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #4 Justin SAAD1001 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #4 Justin SAAD1001 - Expected '$expected_output_4' but got: $newOutput"
  returnStatus=1
fi

expected_output_5="Course name: PROG1400 Course mark: 94"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_5" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #5 Justin PROG1400 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #5 Justin PROG1400 - Expected '$expected_output_5' but got: $newOutput"
  returnStatus=1
fi

expected_output_6="Course name: DBAS4002 Course mark: 75"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_6" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #6 Justin DBAS4002 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #6 Justin DBAS4002 - Expected '$expected_output_6' but got: $newOutput"
  returnStatus=1
fi

expected_output_7="Grade Average: 83.8"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_7" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #7 Justin Grade Average - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #7 Justin Grade Average - Expected '$expected_output_7' but got: $newOutput"
  returnStatus=1
fi

echo
################### JACINDA TESTS ################################

expected_output_8="Student: ID:6666666 Name: Ardern, Jacinda"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_8" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #8 Jacinda Header - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #8 Jacinda Header - Expected '$expected_output_8' but got: $newOutput"
  returnStatus=1
fi

expected_output_9="Course name: OSYS1000 Course mark: 96"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_9" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #9 Jacinda OSYS1000 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #9 Jacinda OSYS1000 - Expected '$expected_output_9' but got: $newOutput"
  returnStatus=1
fi

expected_output_10="Course name: PROG2007 Course mark: 84"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_10" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #10 Jacinda PROG2007 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #10 Jacinda PROG2007 - Expected '$expected_output_10' but got: $newOutput"
  returnStatus=1
fi

expected_output_11="Course name: SAAD1001 Course mark: 75"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_11" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #11 Jacinda SAAD1001 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #11 Jacinda SAAD1001 - Expected '$expected_output_11' but got: $newOutput"
  returnStatus=1
fi

expected_output_12="Course name: PROG1400 Course mark: 98"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_12" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #12 Jacinda PROG1400 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #12 Jacinda PROG1400 - Expected '$expected_output_12' but got: $newOutput"
  returnStatus=1
fi

expected_output_13="Course name: DBAS4002 Course mark: 86"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_13" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #13 Jacinda DBAS4002 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #13 Jacinda DBAS4002 - Expected '$expected_output_13' but got: $newOutput"
  returnStatus=1
fi

expected_output_14="Grade Average: 87.8"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_14" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #14 Jacinda Grade Average - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #14 Jacinda Grade Average - Expected '$expected_output_14' but got: $newOutput"
  returnStatus=1
fi

echo
################### JOE TESTS ################################

expected_output_15="Student: ID:7777777 Name: Biden, Joe"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_15" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #15 Joe Header - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #15 Joe Header - Expected '$expected_output_15' but got: $newOutput"
  returnStatus=1
fi

expected_output_16="Course name: OSYS1000 Course mark: 94"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_16" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #16 Joe OSYS1000 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #16 Joe OSYS1000 - Expected '$expected_output_16' but got: $newOutput"
  returnStatus=1
fi

expected_output_17="Course name: PROG2007 Course mark: 87"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_17" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #17 Joe PROG2007 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #17 Joe PROG2007 - Expected '$expected_output_17' but got: $newOutput"
  returnStatus=1
fi

expected_output_18="Course name: SAAD1001 Course mark: 70"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_18" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #18 Joe SAAD1001 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #18 Joe SAAD1001 - Expected '$expected_output_18' but got: $newOutput"
  returnStatus=1
fi

expected_output_19="Course name: PROG1400 Course mark: 88"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_19" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #19 Joe PROG1400 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #19 Joe PROG1400 - Expected '$expected_output_19' but got: $newOutput"
  returnStatus=1
fi

expected_output_20="Course name: DBAS4002 Course mark: 89"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_20" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #20 Joe DBAS4002 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #20 Joe DBAS4002 - Expected '$expected_output_20' but got: $newOutput"
  returnStatus=1
fi

expected_output_21="Grade Average: 85.6"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_21" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test #21 Joe Grade Average - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #21 Joe Grade Average - Expected '$expected_output_21' but got: $newOutput"
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
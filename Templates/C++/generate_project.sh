usage() {
    echo "usage: ./generate_project.sh --project [project_name] --user [user_name]"
    echo -e "e.g.:\n\t./generate_project.sh --project 001_Two_Sum --user \"Joz Qian\""
}

#appendLine(line, targetFile)
appendLine(){
    echo "$(echo -e $1 | cat - $2)" > $2
}

if [ "$#" -ne 4 ]; then
    usage
    exit 1
fi

project_name=
user_name=
CMAKE_MINIMUM_REQUIRED_VERSION=3.9

while [ "$1" != "" ]; do
    case $1 in
        --project)              shift
                                project_name=$1
                                ;;
        --user)                 shift
                                user_name=$1
                                ;;
        * )                     usage
                                exit 1
    esac
    shift
done

rm -rf $project_name
mkdir $project_name
cp -R Template/* $project_name

#Root CMakeLists.txt
appendLine \
"\
cmake_minimum_required(VERSION $CMAKE_MINIMUM_REQUIRED_VERSION)\n\
project($project_name)\
" \
"$project_name/CMakeLists.txt"

#test/test.cpp
appendLine \
"\
//  test.cpp\n\
//  $project_name\n\
//  \n\
//  Create by $user_name on $(date +%m/%d/%y)\n\
//  \n\
" \
"$project_name/test/test.cpp"

#src/Solution.cpp
appendLine \
"\
//  Solution.cpp\n\
//  $project_name\n\
//  \n\
//  Create by $user_name on $(date +%m/%d/%y)\n\
//  \n\
" \
"$project_name/src/Solution.cpp"

#src/Solution.h
appendLine \
"\
//  Solution.h\n\
//  $project_name\n\
//  \n\
//  Create by $user_name on $(date +%m/%d/%y)\n\
//  \n\n\
#ifndef INC_$(echo $project_name)_SOLUTION_H\n\
#define INC_$(echo $project_name)_SOLUTION_H\n\n\
class Solution {\n\
public:\n\n\
};\n\n\
#endif //INC_$(echo $project_name)_SOLUTION_H\n\
" \
"$project_name/src/Solution.h"

#main/main.cpp
appendLine \
"\
//  main.cpp\n\
//  $project_name\n\
//  \n\
//  Create by $user_name on $(date +%m/%d/%y)\n\
//  \n\n\
#include \"Solution.h\"\n\
" \
"$project_name/main/main.cpp"


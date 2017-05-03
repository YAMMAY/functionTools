/*=============================================================================
#     FileName: readDIr.txt
#         Desc: 
#       Author: siyuan.yu
#        Email: 1010582011@qq.com

#      Version: 0.0.1
#   LastChange: 2017-05-03 19:20:53
#      History:
=============================================================================*/
#include <dirent.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::vector<std::string> load_dir_files(const char *dir)
{
    DIR *dp;
    struct dirent *ep;
    char filename[PATH_MAX];
    dp = opendir(dir);
    if(dp == NULL) std::cout<< dir << " not exists";
	std::vector<std::string> files;
    while((ep = readdir(dp)))
    {
        if(ep->d_name[0] == '.')
            continue;
        sprintf(filename, "%s/%s", dir, ep->d_name);
        files.push_back(std::string(filename));
    }
    closedir(dp);
	std::sort(files.begin(), files.end());
    return files;
}
void printUsage()
{
	std::cout<<"Usage:./main dirname\n";
}
void showAllFiles(const std::vector<std::string> &files)
{
	for(std::vector<std::string>::const_iterator iter=files.begin();iter!=files.end();iter++)
		std::cout<<*iter<<std::endl;
}
int main(int argc, char **argv)
{
	if(argc<2)
	{
		printUsage();
		return 0;
	}
	std::vector<std::string> files;
	files=load_dir_files(argv[1]);
	showAllFiles(files);
	return 0;
}

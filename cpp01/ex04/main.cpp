#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

void	copyReplace(std::fstream &in_fs, std::fstream &out_fs, std::string &s1, std::string &s2)
{
	std::string	line;
	while (std::getline(in_fs, line))
	{
		std::size_t	position = 0;
		while ((position = line.find(s1, position)) != std::string::npos)
		{
			line.erase(position, s1.length());
			line.insert(position, s2);
			position += s2.length();
		}
		out_fs << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "USAGE ./mySed <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	else
	{
		std::string	infile(argv[1]);
		std::string	s1(argv[2]);
		std::string	s2(argv[3]);

		if (s1.empty())
		{
			std::cout << "Error: s1 cannot be empty." << std::endl;
			return 2;
		}

		std::fstream	in_fs;
		in_fs.open(infile.c_str(), std::fstream::in);
		if (!in_fs.is_open())
		{
			std::cout << "Error: cannot open infile." << std::endl;
			return 3;
		}

		std::string	outfile;
		outfile = infile.append(".replace");

		std::fstream	out_fs;
		out_fs.open(outfile.c_str(), std::fstream::out);
		if (!out_fs.is_open())
		{
			std::cout << "Error: cannot generate new file." << std::endl;
			in_fs.close();
			return 4;
		}

		copyReplace(in_fs, out_fs, s1, s2);
		in_fs.close();
		out_fs.close();
	}
}
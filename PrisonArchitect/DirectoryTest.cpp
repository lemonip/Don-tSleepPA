#include "stdafx.h"
#include "DirectoryTest.h"

#include <filesystem>
#include <iostream>

HRESULT DirectoryTest::init()
{
/*
	std::filesystem::path p("./some_file");

	std::cout << "Does " << p << " exist? [" << std::boolalpha
		<< std::filesystem::exists(p) << "]" << std::endl;
	std::cout << "Is " << p << " file? [" << std::filesystem::is_regular_file(p)
		<< "]" << std::endl;
	std::cout << "Is " << p << " directory? [" << std::filesystem::is_directory(p)
		<< "]" << std::endl;*/

	//for (auto& p : fs::recursive_directory_iterator(path)) {
	//	cout << p << endl; //결과: root/dir1/text.txt
	//	cout << p.path().filename() << endl; //결과: "test.txt"
	//	cout << p.path().filename().string() << endl; //결과: test.txt
	//}

	return S_OK;
}

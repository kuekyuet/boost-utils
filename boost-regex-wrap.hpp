#ifndef BOOST_REGEX_WRAP_HPP
#define BOOST_REGEX_WRAP_HPP

#include <string>
#include <boost/regex.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>  


using namespace boost::xpressive;  

//判断是否含有中文,ASCII
bool contains_chs(const std::wstring& target){
	bool flag = false;

	if(!target.empty()){
		boost::wregex word_regex(L"[\u4e00-\u9fa5]");
		boost::wsmatch match_temp;
		std::wstring::const_iterator str_begin = wtarget.begin();
		std::wstring::const_iterator str_end = wtarget.end();
		if (wtarget.size() > 3)
		{
			flag  = boost::regex_search(str_begin,str_end,match_temp,word_regex);
		}
	}

	return flag;
}

//判断是否含有中文,unicode
bool contains_wchs(const std::string& target){
	bool flag = false;
	if(!target.empty()){
		boost::regex word_regex("[\u4e00-\u9fa5]");
		boost::smatch match_temp;
		std::string::const_iterator str_begin = target.begin();
		std::string::const_iterator str_end = target.end();
		if (target.size() > 3)
		{
			flag  = boost::regex_search(str_begin,str_end,match_temp,word_regex);
		}
	}

	return flag;
}

//check if ip input  is ipv4
bool is_ipv4(const std::string& ip_to_check){

	cregex regex_ip = cregex::compile("(25[0-4]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[1-9])[.](25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[.](25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[.](25[0-4]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[1-9])");
	bool ipv4 = regex_match(ip_to_check.c_str(), regex_ip);
	return ipv4;
}


#endif // BOOST_REGEX_WRAP_HPP

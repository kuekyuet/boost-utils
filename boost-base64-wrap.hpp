#ifndef BOOST_BASE64_WRAP_HPP
#define BOOST_BASE64_WRAP_HPP


#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <string>
#include <iostream>
#include <sstream>

inline bool BoostBase64Encode(const std::string& input, std::string& output) {
	typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<std::string::const_iterator, 6, 8> > Base64EncodeIterator;
	std::stringstream result;
	std::copy(Base64EncodeIterator(input.begin()) , Base64EncodeIterator(input.end()), std::ostream_iterator<char>(result));
	size_t equal_count = (3 - input.length() % 3) % 3;
	for (size_t i = 0; i < equal_count; i++) {
		result.put('=');
	}
	output = result.str();
	return output.empty() == false;
}

inline bool BoostBase64Decode(const std::string& input, std::string& output) {
	typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<std::string::const_iterator>, 8, 6> Base64DecodeIterator;
	std::stringstream result;
	try {
		std::copy(Base64DecodeIterator(input.begin()) , Base64DecodeIterator(input.end()), std::ostream_iterator<char>(result));
	} catch(...) {
		return false;
	}
	output = result.str();
	return output.empty() == false;
}

static int BoostBase64Test()
{

	std::string input_str("{\"digit\":0,\"pcver\":0,\"protocol\":30001}\n");
	std::string base64_str, output_str;

	std::cout<<"origin text: \n"<<input_str<<std::endl;

	BoostBase64Encode(input_str, base64_str);
	std::cout<<"encode: \n"<<base64_str<<std::endl;

	BoostBase64Decode(base64_str, output_str);
	std::cout<<"decode: \n"<<output_str<<std::endl;

	return 0;
}

#endif // BOOST_BASE64_WRAP_HPP

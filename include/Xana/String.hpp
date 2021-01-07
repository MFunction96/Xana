//
// Created by MFunction on 01/07/2021.
//

#ifndef XANA_STRING_HPP
#define XANA_STRING_HPP

#include "Xana/Object.hpp"


namespace Xana {
	class String : public Object, public std::string {
	public:
		explicit String();

		explicit String(std::string & str);

		bool operator==(boost::shared_ptr<Object> obj) const;

		boost::shared_ptr<String> GetHashCode() const;

		boost::shared_ptr<String> ToString() const;

		bool Equals(boost::shared_ptr<Object> obj) const;

		boost::shared_ptr<Object> Clone() const;
	};
}

#endif //XANA_STRING_HPP

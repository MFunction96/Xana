//
// Created by MFunction on 01/07/2021.
//

#include "Xana/String.hpp"

namespace Xana {
	String::String() : std::string("") {

	}

	String::String(std::string &str) : std::string(str) {

	}

	bool String::operator==(boost::shared_ptr<Object> obj) const {
		return this->Equals(obj);
	}


	boost::shared_ptr<String> Xana::String::GetHashCode() const {
		return boost::make_shared<String>(String());
	}

	boost::shared_ptr<String> String::ToString() const {
		return boost::make_shared<String>(String());
	}

	bool String::Equals(boost::shared_ptr<Object> obj) const {
		return boost::dynamic_pointer_cast<String>(Clone()) == boost::dynamic_pointer_cast<String>(obj);
	}

	boost::shared_ptr<Object> String::Clone() const {
		return boost::make_shared<String>(String(*this));
	}

}



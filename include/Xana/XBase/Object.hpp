//
// Created by MFunction on 09/16/2020.
//

#ifndef _XANA_XBASE_OBJECT_H
#define _XANA_XBASE_OBJECT_H

// Include standard headers
#include <bits/stdc++.h>
// Include boost headers
#include <boost/smart_ptr.hpp>

namespace Xana {
	namespace XBase {
		class Object : public boost::enable_shared_from_this<Object> {
		public:
			virtual bool operator==(boost::shared_ptr<Object> obj) const = 0;

			virtual std::string &GetHashCode() const = 0;

			virtual std::string &ToString() const = 0;

			virtual bool Equals(boost::shared_ptr<Object> obj) const = 0;
		};
	}
}

#endif //_XANA_XBASE_OBJECT_H

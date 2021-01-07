//
// Created by MFunction on 09/16/2020.
//

#ifndef _XANA_OBJECT_H
#define _XANA_OBJECT_H

// Include standard headers
#include <bits/stdc++.h>
// Include boost headers
#include <boost/smart_ptr.hpp>
#include <boost/type_traits.hpp>

namespace Xana {
	class Object;
	class String;
	class Object : public boost::enable_shared_from_this<Object> {
	public:
		virtual bool operator==(boost::shared_ptr<Object> obj) const = 0;

		virtual boost::shared_ptr<String> GetHashCode() const = 0;

		virtual boost::shared_ptr<String> ToString() const = 0;

		virtual bool Equals(boost::shared_ptr<Object> obj) const = 0;

		virtual boost::shared_ptr<Object> Clone() const = 0;
	};
}

#endif //_XANA_OBJECT_H

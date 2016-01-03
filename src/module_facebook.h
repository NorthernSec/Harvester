#ifndef MODULE_FACEBOOK_H
#define MODULE_FACEBOOK_H
/*
 * Module Facebook:
 *	Explain this stuff. Too lazy now.
 */
#include "module.h"

class module_facebook : public module {
public:
	virtual void		init_module(logger *);
	virtual void		perform_search(const std::string &);
private:
};

#endif

#ifndef _NESTED_H
#define _NESTED_H

#define	csetChomp(path)	{			\
	char	*slash = strrchr(path, '/');	\
	assert(slash);				\
	*slash = 0;				\
	}

typedef struct {
	void	**repos;	// addlines of pointers to repo's
	char	*rootkey;	// points at repos[i]->rootkey
	char	*deltakey;	// ditto
	char	*path;		// ditto
	u32	new:1;		// ditto
	int	index;		// used by the iterator
} repos;

typedef	struct {
	sccs	*sc;		// product changeset file if set
	char	*rev;		// if set, we want the deltakeys as of this
	char	**revs;		// if set, limit the components to these csets 
	u32	product:1;	// include the product in the list
	u32	present:1;	// return components iff present
	u32	product_first:1;// default is last in list
} eopts;

repos*	ensemble_list(eopts opts);
repos*	ensemble_first(repos *repos);
repos*	ensemble_next(repos *repos);
void	ensemble_free(repos *repos);

int	ensemble_each(int quiet, int ac, char **av);

#define	EACH_REPO(c)	for (ensemble_first(c); (c)->index; ensemble_next(c))

#endif /* _NESTED_H */
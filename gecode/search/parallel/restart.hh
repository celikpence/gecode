/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Christian Schulte, 2009
 *
 *  Last modified:
 *     $Date: 2009-05-13 13:48:34 +0100 (Wed, 13 May 2009) $ by $Author: schulte $
 *     $Revision: 9085 $
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __GECODE_SEARCH_PARALLEL_RESTART_HH__
#define __GECODE_SEARCH_PARALLEL_RESTART_HH__

#include <gecode/search/parallel/dfs.hh>

namespace Gecode { namespace Search { namespace Parallel {

  /// Depth-first restart best solution search engine implementation
  class Restart : public DFS {
  protected:
    /// Root node
    Space* root;
    /// So-far best solution
    Space* best;
    /// Whether a reset is needed
    bool reset_needed;
  public:
    /// Initialize engine for space \a s (with size \a sz) and options \a o
    Restart(Space* s, size_t sz, const Search::Options& o);
    /// Return next better solution (NULL, if none exists or search has been stopped)
    virtual Space* next(void);
    /// Destructor
    virtual ~Restart(void);
  };

  forceinline 
  Restart::Restart(Space* s, size_t sz, const Search::Options& o) :
    DFS(s,sz,o),
    root(s->status() == SS_FAILED ? NULL : s->clone()), 
    best(NULL), reset_needed(false) {}

}}}

#endif

// STATISTICS: search-parallel

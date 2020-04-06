---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# {{ site.title }}

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions)
<a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

{% if site.github.project_tagline %}{{ site.github.project_tagline }}{% else %}This documentation is automatically generated by <a href="https://github.com/kmyk/online-judge-verify-helper">online-judge-verify-helper</a>.{% endif %}

## Library Files

<div id="e73c6b5872115ad0f2896f8e8476ef39"></div>

### src/DataStructure

* :warning: <a href="library/src/DataStructure/Accumulate2D.hpp.html">src/DataStructure/Accumulate2D.hpp</a>
* :warning: <a href="library/src/DataStructure/ConvexHullTrick.hpp.html">src/DataStructure/ConvexHullTrick.hpp</a>
* :warning: <a href="library/src/DataStructure/Doubling.hpp.html">src/DataStructure/Doubling.hpp</a>
* :warning: <a href="library/src/DataStructure/DynamicUnionFind.hpp.html">src/DataStructure/DynamicUnionFind.hpp</a>
* :warning: <a href="library/src/DataStructure/FenwickTree.hpp.html">src/DataStructure/FenwickTree.hpp</a>
* :warning: <a href="library/src/DataStructure/Imos2D.hpp.html">src/DataStructure/Imos2D.hpp</a>
* :heavy_check_mark: <a href="library/src/DataStructure/LazySegmentTree.hpp.html">src/DataStructure/LazySegmentTree.hpp</a>
* :warning: <a href="library/src/DataStructure/QuickFind.hpp.html">src/DataStructure/QuickFind.hpp</a>
* :warning: <a href="library/src/DataStructure/ReversedBinaryIndexedTree.hpp.html">src/DataStructure/ReversedBinaryIndexedTree.hpp</a>
* :heavy_check_mark: <a href="library/src/DataStructure/SegmentTree.hpp.html">src/DataStructure/SegmentTree.hpp</a>
* :warning: <a href="library/src/DataStructure/SlideMin.hpp.html">src/DataStructure/SlideMin.hpp</a>
* :heavy_check_mark: <a href="library/src/DataStructure/UnionFind.hpp.html">src/DataStructure/UnionFind.hpp</a>
* :warning: <a href="library/src/DataStructure/UnionFindRange.hpp.html">src/DataStructure/UnionFindRange.hpp</a>
* :warning: <a href="library/src/DataStructure/UnionFindWithData.hpp.html">src/DataStructure/UnionFindWithData.hpp</a>
* :warning: <a href="library/src/DataStructure/UnionFindWithWeight.hpp.html">src/DataStructure/UnionFindWithWeight.hpp</a>


<div id="29f578163eb30c67e395a84ad90553a2"></div>

### src/Flow

* :warning: <a href="library/src/Flow/Dinic.hpp.html">src/Flow/Dinic.hpp</a>
* :warning: <a href="library/src/Flow/FordFulkerson.hpp.html">src/Flow/FordFulkerson.hpp</a>


<div id="426bb254552b21fb2d009880f952cd8b"></div>

### src/Geometry

* :warning: <a href="library/src/Geometry/Geometry.hpp.html">src/Geometry/Geometry.hpp</a>


<div id="6e5c608398952d411d1862b1f8dc05f5"></div>

### src/Graph

* :warning: <a href="library/src/Graph/AbstractDijkstra.hpp.html">src/Graph/AbstractDijkstra.hpp</a>
* :warning: <a href="library/src/Graph/AllDirectionTreeDP.hpp.html">src/Graph/AllDirectionTreeDP.hpp</a>
* :warning: <a href="library/src/Graph/BellmanFord.hpp.html">src/Graph/BellmanFord.hpp</a>
* :warning: <a href="library/src/Graph/Boruvka.hpp.html">src/Graph/Boruvka.hpp</a>
* :warning: <a href="library/src/Graph/Dijkstra.hpp.html">src/Graph/Dijkstra.hpp</a>
* :warning: <a href="library/src/Graph/ErdosGallai.hpp.html">src/Graph/ErdosGallai.hpp</a>
* :warning: <a href="library/src/Graph/GridGraph.hpp.html">src/Graph/GridGraph.hpp</a>
* :warning: <a href="library/src/Graph/Kruskal.hpp.html">src/Graph/Kruskal.hpp</a>
* :heavy_check_mark: <a href="library/src/Graph/LowestCommonAncestor.hpp.html">src/Graph/LowestCommonAncestor.hpp</a>
* :heavy_check_mark: <a href="library/src/Graph/StronglyConnectedComponents.hpp.html">src/Graph/StronglyConnectedComponents.hpp</a>
* :warning: <a href="library/src/Graph/TreeDiameter.hpp.html">src/Graph/TreeDiameter.hpp</a>
* :heavy_check_mark: <a href="library/src/Graph/TwoEdgeConnectedComponents.hpp.html">src/Graph/TwoEdgeConnectedComponents.hpp</a>
* :warning: <a href="library/src/Graph/WarshallFloyd.hpp.html">src/Graph/WarshallFloyd.hpp</a>


<div id="1b49b634354b8edb1dc8ef8a73014950"></div>

### src/Helper

* :warning: <a href="library/src/Helper/ArithmeticParser.hpp.html">src/Helper/ArithmeticParser.hpp</a>
* :warning: <a href="library/src/Helper/BinarySearch.hpp.html">src/Helper/BinarySearch.hpp</a>
* :warning: <a href="library/src/Helper/BitOperation.hpp.html">src/Helper/BitOperation.hpp</a>
* :heavy_check_mark: <a href="library/src/Helper/ChminChmax.hpp.html">src/Helper/ChminChmax.hpp</a>
* :warning: <a href="library/src/Helper/Directions.hpp.html">src/Helper/Directions.hpp</a>
* :warning: <a href="library/src/Helper/EnumerateFixedSizeSet.hpp.html">src/Helper/EnumerateFixedSizeSet.hpp</a>
* :warning: <a href="library/src/Helper/GccTree.hpp.html">src/Helper/GccTree.hpp</a>
* :heavy_check_mark: <a href="library/src/Helper/MakeVec.hpp.html">src/Helper/MakeVec.hpp</a>
* :warning: <a href="library/src/Helper/MsbLsb.hpp.html">src/Helper/MsbLsb.hpp</a>
* :warning: <a href="library/src/Helper/Random.hpp.html">src/Helper/Random.hpp</a>
* :warning: <a href="library/src/Helper/Rotate2D.hpp.html">src/Helper/Rotate2D.hpp</a>
* :warning: <a href="library/src/Helper/TreeDFS.hpp.html">src/Helper/TreeDFS.hpp</a>
* :warning: <a href="library/src/Helper/TreeInput.hpp.html">src/Helper/TreeInput.hpp</a>


<div id="64f6d80a21cfb0c7e1026d02dde4f7fa"></div>

### src/Math

* :warning: <a href="library/src/Math/ChineseRemainderTheorem.hpp.html">src/Math/ChineseRemainderTheorem.hpp</a>
* :heavy_check_mark: <a href="library/src/Math/Combination.hpp.html">src/Math/Combination.hpp</a>
* :warning: <a href="library/src/Math/Divisor.hpp.html">src/Math/Divisor.hpp</a>
* :heavy_check_mark: <a href="library/src/Math/Eratosthenes.hpp.html">src/Math/Eratosthenes.hpp</a>
* :warning: <a href="library/src/Math/EulerTotient.hpp.html">src/Math/EulerTotient.hpp</a>
* :warning: <a href="library/src/Math/FFT.hpp.html">src/Math/FFT.hpp</a>
* :warning: <a href="library/src/Math/GaussJordan.hpp.html">src/Math/GaussJordan.hpp</a>
* :warning: <a href="library/src/Math/Matrix.hpp.html">src/Math/Matrix.hpp</a>
* :warning: <a href="library/src/Math/MillerRabin.hpp.html">src/Math/MillerRabin.hpp</a>
* :heavy_check_mark: <a href="library/src/Math/ModInt.hpp.html">src/Math/ModInt.hpp</a>


<div id="ac276d2326c527c8c7dbcbb63d85c6c7"></div>

### src/String

* :warning: <a href="library/src/String/LongestCommonPrefix.hpp.html">src/String/LongestCommonPrefix.hpp</a>
* :warning: <a href="library/src/String/LongestCommonSubsequence.hpp.html">src/String/LongestCommonSubsequence.hpp</a>
* :warning: <a href="library/src/String/Manacher.hpp.html">src/String/Manacher.hpp</a>
* :warning: <a href="library/src/String/MultisetHash.hpp.html">src/String/MultisetHash.hpp</a>
* :heavy_check_mark: <a href="library/src/String/RollingHash.hpp.html">src/String/RollingHash.hpp</a>
* :warning: <a href="library/src/String/SuffixArray.hpp.html">src/String/SuffixArray.hpp</a>
* :warning: <a href="library/src/String/SuffixArrayDoubling.hpp.html">src/String/SuffixArrayDoubling.hpp</a>
* :warning: <a href="library/src/String/Trie.hpp.html">src/String/Trie.hpp</a>
* :heavy_check_mark: <a href="library/src/String/ZAlgorithm.hpp.html">src/String/ZAlgorithm.hpp</a>


<div id="ed8431f95262b19a48e972d3753d06d7"></div>

### src/old

* :warning: <a href="library/src/old/DynamicModInt.hpp.html">src/old/DynamicModInt.hpp</a>


## Verify Files

* :heavy_check_mark: <a href="verify/test/aoj/DPL_1_E.test.cpp.html">test/aoj/DPL_1_E.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_D_runtime.test.cpp.html">test/aoj/DPL_5_D_runtime.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/enumerate_primes.test.cpp.html">test/yosupo/enumerate_primes.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/staticrmq.test.cpp.html">test/yosupo/staticrmq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/two_edge_connected_components.test.cpp.html">test/yosupo/two_edge_connected_components.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/zalgorithm_rolling_hash.test.cpp.html">test/yosupo/zalgorithm_rolling_hash.test.cpp</a>


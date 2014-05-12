var _=require('underscore-node');
var hoge = _.range(1,20,3);
_.each(hoge,function(val){console.log(val*2)});
console.log(_.map(hoge,function(val){return val * 2}));

var product = _.reduce(hoge, 
    function(memo, value){ return memo * value}
    );
console.log( product );

var members = [
  { 'name': 'chiba', 'age': 25},
  { 'name': 'kuhara', 'age': 24},
  { 'name': 'abe', 'age': 26},
  { 'name': 'ueno', 'age': 27}
];

var get = function(name){
  return _.find(members,
      function(member){
        return member.name == name
      })
};

console.log(get('chiba'));

var getmemo = _.memoize(get);

console.log(getmemo('chiba'));
console.log(getmemo('chiba')); // キャッシュ

var fibonacchi = _.memoize(function(n){
  return n<2 ? n: fibonacchi(n-1) + fibonacchi(n-2);
});

var data = _.range(1,20);

console.log(_.map(data,function(val){ return fibonacchi(val)}));

console.log(_.uniqueId());
console.log(_.uniqueId());
console.log(_.uniqueId());

var str = '"Asai", "Nakamura", & "Terui"';
console.log(_.escape(str));

var template = _.template("hello! <%= name %>!!");

var c = function(msg){ console.log(msg)};
c(template({name: 'ai'}));


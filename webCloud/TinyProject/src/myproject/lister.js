(function() {
  var app = angular.module('ListeStore', []);
  app.controller('ScoreController', function() {
  });

  app.controller("ListeControllerHTTP", ["$http", function($http) {
    var endpoint = 'https://1-dot-tinypet-1133.appspot.com/_ah/api/signatureentityendpoint/v1/signatureentity';

    aliasdethis = this;
    aliasdethis.petition = {};
    $http.get(endpoint).then(function(datas) {
      aliasdethis.petitions = datas.data.items;

    }, function(error) {
      console.log("Error endpoint");
    });

    aliasdethis.display = function() {
      console.log(aliasdethis.petitions);
    };
  }]);
})();
(function() {
  var app = angular.module('PetitionsStore', []);
  app.controller('CreateController', function($scope) {
    var petitions = $scope.petitions = [];
    var noms = $scope.noms = [];

        $scope.addName = function () {

            var newName = $scope.newName.trim();
            if (!newName.length) {
                // éviter les todos vides
                return;
            }
            todos.push({
                // on ajoute le todo au tableau des todos
                title: newName,
                completed: false
            });
            // Réinitialisation de la variable newTodo
            $scope.newName = '';
        };

        // Enlever un todo
        $scope.removeTodo = function (todo) {
            todos.splice(todos.indexOf(todo), 1);
        };

        // Cocher / Décocher tous les todos
        $scope.markAll = function (completed) {
            todos.forEach(function (todo) {
                todo.completed = !completed;
            });
        };

        // Enlever tous les todos cochés
        $scope.clearCompletedTodos = function () {
            $scope.todos = todos = todos.filter(function (todo) {
                return !todo.completed;
            });
        };
  });

  app.controller("CreateControllerHTTP", ["$http", function($http) {
   /* var endpoint = 'https://1-dot-tinypet-1133.appspot.com/_ah/api/signatureentityendpoint/v1/signatureentity?fields=id%2Cname%2Cpetition';
    aliasdethis = this;
    aliasdethis.petition = {};
    $http.post(endpoint).then(function() {
      console.log(aliasdethis);
      aliasdethis.id = "test1";
    }, function(error) {
      console.log("Error endpoint");
    });

    aliasdethis.display = function() {
      console.log(aliasdethis);
    };*/
  }]);
})();
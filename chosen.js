(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context) {
      $(Drupal.settings.chosen.selector, context).chosen(); 
    }
  }
})(jQuery);
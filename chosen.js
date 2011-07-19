(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context) {
      $(Drupal.settings.chosen.selectors).chosen(); 
    }
  }
})(jQuery);
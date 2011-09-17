(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context) {
      $(Drupal.settings.chosen.selector, context)
        .add('.chosen-widget') //enable chosen for widgets
        .not('#field-ui-field-overview-form select, #field-ui-display-overview-form select') //disable chosen on field ui
        .each(function() {
        if ($(this).find('option').size() >= Drupal.settings.chosen.minimum) {
          $(this).chosen();
        }
      }); 
    }
  }
})(jQuery);
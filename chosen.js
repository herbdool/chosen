// $Id$
Drupal.behaviors.chosen = {
  attach: function(context, settings) {
    jQuery(Drupal.settings.chosen.selectors).chosen(); 
  }
}

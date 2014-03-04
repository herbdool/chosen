(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context, settings) {
      settings.chosen = settings.chosen || Drupal.settings.chosen;
      var minOptionsSingle = settings.chosen.minimum_single;
      var minOptionsMultiple = settings.chosen.minimum_multiple;
      var minOptions;
      // Define options.
      var multiple = Drupal.settings.chosen.multiple;
      var maxSelectedOptions = Drupal.settings.chosen.max_selected_options;

      // Prepare selector and add unwantend selectors.
      var selector = settings.chosen.selector;

      // Function to prepare all the options together for the chosen() call.
      var getElementOptions = function (element) {
        var options = jQuery.extend({}, settings.chosen.options);
        // The width default option is considered the minimum width, so this
        // must be evaluated for every option.
        if ($(element).width() > options.width) {
          options.width = $(element).width() + 'px';
        }
        else {
          // Default width is a number so we need to add 'px' to make it work.
          options.width += 'px';
        }
        return options;
      };

      $(selector, context)
        .not('#field-ui-field-overview-form select, #field-ui-display-overview-form select, .wysiwyg, .draggable select[name$="[weight]"], .draggable select[name$="[position]"]') //disable chosen on field ui
        .each(function() {
          var name = $(this).attr('name');
          options = getElementOptions(this);

          minOptions = minOptionsSingle;
          if (multiple[name] !== false) {
            minOptions = minOptionsMultiple;
          }

          if (maxSelectedOptions[name] !== false) {
           options.max_selected_options = maxSelectedOptions[name];
          }

          if ($(this).find('option').size() >= minOptions || minOptions == 'Always Apply') {
            $(this).chosen(options);
          }
      });

      // Enable chosen for widgets.
      $('select.chosen-widget', context).each(function() {
        options = getElementOptions(this);
        $(this).chosen(options);
      });
    }
  };
})(jQuery);
